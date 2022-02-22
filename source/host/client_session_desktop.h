//
// Aspia Project
// Copyright (C) 2016-2022 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef HOST_CLIENT_SESSION_DESKTOP_H
#define HOST_CLIENT_SESSION_DESKTOP_H

#include "base/macros_magic.h"
#include "base/protobuf_arena.h"
#include "base/desktop/geometry.h"
#include "base/memory/local_memory.h"
#include "host/client_session.h"
#include "host/desktop_session.h"

namespace base {
class AudioEncoder;
class CursorEncoder;
class Frame;
class MouseCursor;
class ScaleReducer;
class VideoEncoder;
} // namespace base

namespace host {

class DesktopSessionProxy;

class ClientSessionDesktop
    : public base::ProtobufArena,
      public ClientSession
{
public:
    ClientSessionDesktop(proto::SessionType session_type,
                         std::unique_ptr<base::NetworkChannel> channel,
                         std::shared_ptr<base::TaskRunner> task_runner);
    ~ClientSessionDesktop() override;

    void setDesktopSessionProxy(base::local_shared_ptr<DesktopSessionProxy> desktop_session_proxy);

    void encodeScreen(const base::Frame* frame, const base::MouseCursor* cursor);
    void encodeAudio(const proto::AudioPacket& audio_packet);
    void setCursorPosition(const proto::CursorPosition& cursor_position);
    void setScreenList(const proto::ScreenList& list);
    void injectClipboardEvent(const proto::ClipboardEvent& event);

    const DesktopSession::Config& desktopSessionConfig() const { return desktop_session_config_; }

protected:
    // net::Listener implementation.
    void onMessageReceived(const base::ByteArray& buffer) override;
    void onMessageWritten(size_t pending) override;

    // ClientSession implementation.
    void onStarted() override;

private:
    void readExtension(const proto::DesktopExtension& extension);
    void readConfig(const proto::DesktopConfig& config);

    base::local_shared_ptr<DesktopSessionProxy> desktop_session_proxy_;
    std::unique_ptr<base::ScaleReducer> scale_reducer_;
    std::unique_ptr<base::VideoEncoder> video_encoder_;
    std::unique_ptr<base::CursorEncoder> cursor_encoder_;
    std::unique_ptr<base::AudioEncoder> audio_encoder_;
    DesktopSession::Config desktop_session_config_;
    base::Size source_size_;
    base::Size preferred_size_;

    DISALLOW_COPY_AND_ASSIGN(ClientSessionDesktop);
};

} // namespace host

#endif // HOST_CLIENT_SESSION_DESKTOP_H
