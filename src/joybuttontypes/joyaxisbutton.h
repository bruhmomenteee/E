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

#ifndef JOYAXISBUTTON_H
#define JOYAXISBUTTON_H

#include "joybuttontypes/joygradientbutton.h"
#include "logger.h"

class VDPad;
class SetJoystick;
class JoyAxis;

class JoyAxisButton : public JoyGradientButton
{
    Q_OBJECT

  public:
    explicit JoyAxisButton(JoyAxis *axis, int index, int originset, SetJoystick *parentSet, QObject *parent);

    virtual QString getPartialName(bool forceFullFormat = false, bool displayNames = false) const;
    virtual QString getXmlName();
    virtual double getDistanceFromDeadZone();

    virtual double getMouseDistanceFromDeadZone();
    virtual double getLastMouseDistanceFromDeadZone();

    virtual void setChangeSetCondition(SetChangeCondition condition, bool passive = false, bool updateActiveString = true);
    virtual void setVDPad(VDPad *vdpad);
    virtual void setTurboMode(TurboMode mode);
    virtual bool isPartRealAxis();

    virtual double getAccelerationDistance();
    virtual double getLastAccelerationDistance();

    JoyAxis *getAxis() const;

  signals:
    void setAssignmentChanged(int current_button, int axis_index, int associated_set, int mode);

  private:
    JoyAxis *m_axis;
};

#endif // JOYAXISBUTTON_H
