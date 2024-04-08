//
// Aspia Project
// Copyright (C) 2016-2024 Dmitry Chapyshev <dmitry@aspia.ru>
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

#ifndef CONSOLE_UPDATE_SETTINGS_DIALOG_H
#define CONSOLE_UPDATE_SETTINGS_DIALOG_H

#include "base/macros_magic.h"
#include "ui_update_settings_dialog.h"

namespace console {

class UpdateSettingsDialog final : public QDialog
{
    Q_OBJECT

public:
    UpdateSettingsDialog(QWidget* parent = nullptr);
    ~UpdateSettingsDialog() final;

private:
    Ui::UpdateSettingsDialog ui;

    DISALLOW_COPY_AND_ASSIGN(UpdateSettingsDialog);
};

} // namespace console

#endif // CONSOLE_UPDATE_SETTINGS_DIALOG_H
