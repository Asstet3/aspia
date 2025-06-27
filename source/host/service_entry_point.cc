//
// Aspia Project
// Copyright (C) 2016-2025 Dmitry Chapyshev <dmitry@aspia.ru>
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

#include "host/ui/host_main.h"

#include <string>
#include <vector>

#include "base/strings/string_util.h"
#include "build/build_config.h"

//--------------------------------------------------------------------------------------------------
#if defined(OS_WIN)
int wmain(int argc, wchar_t* argv[])
{
    std::vector<std::string> argv_utf8;
    argv_utf8.reserve(argc);
    for (int i = 0; i < argc; ++i)
    {
        argv_utf8.push_back(base::utf8FromUtf16(argv[i]));
    }

    std::vector<char*> argv_c_str;
    argv_c_str.reserve(argc);
    for (int i = 0; i < argc; ++i)
    {
        argv_c_str.push_back(argv_utf8[i].data());
    }

    return hostMain(argc, argv_c_str.data());
}
#else
int main(int argc, char* argv[])
{
    return hostMain(argc, argv);
}
#endif
