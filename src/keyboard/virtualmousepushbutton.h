/* antimicrox Gamepad to KB+M event mapper
 * Copyright (C) 2015 Travis Nickles <nickles.travis@gmail.com>
 * Copyright (C) 2020 Jagoda Górska <juliagoda.pl@protonmail>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef VIRTUALMOUSEPUSHBUTTON_H
#define VIRTUALMOUSEPUSHBUTTON_H

#include <QPushButton>

#include <joybuttonslot.h>

/**
 * @brief PushButton representing mouse action in VirtualKeyboardMouseWidget
 *
 */
class VirtualMousePushButton : public QPushButton
{
    Q_OBJECT

  public:
    explicit VirtualMousePushButton(QString displayText, int code, JoyButtonSlot::JoySlotInputAction mode,
                                    QWidget *parent = nullptr);

    int getMouseCode() const;
    JoyButtonSlot::JoySlotInputAction getMouseMode() const;

  signals:
    void mouseSlotCreated(JoyButtonSlot *tempslot);

  private slots:
    void createTempSlot();

  private:
    int code;
    JoyButtonSlot::JoySlotInputAction mode;
};

#endif // VIRTUALMOUSEPUSHBUTTON_H
