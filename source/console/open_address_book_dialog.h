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

#ifndef CONSOLE_OPEN_ADDRESS_BOOK_DIALOG_H
#define CONSOLE_OPEN_ADDRESS_BOOK_DIALOG_H

#include "base/macros_magic.h"
#include "proto/address_book.pb.h"
#include "ui_open_address_book_dialog.h"

namespace console {

class OpenAddressBookDialog : public QDialog
{
    Q_OBJECT

public:
    OpenAddressBookDialog(QWidget* parent,
                          const QString& file_path,
                          proto::address_book::EncryptionType encryption_type);
    ~OpenAddressBookDialog() override;

    QString password() const;

private slots:
    void showPasswordButtonToggled(bool checked);
    void buttonBoxClicked(QAbstractButton* button);

private:
    Ui::OpenAddressBookDialog ui;

    DISALLOW_COPY_AND_ASSIGN(OpenAddressBookDialog);
};

} // namespace console

#endif // CONSOLE_OPEN_ADDRESS_BOOK_DIALOG_H
