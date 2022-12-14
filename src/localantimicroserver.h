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

#ifndef LOCALANTIMICROSERVER_H
#define LOCALANTIMICROSERVER_H

#include <QLocalSocket>
#include <QObject>

class QLocalServer;

/**
 * @brief Class used for checking presence of other AntiMicroX instances and communicating with them.
 */
class LocalAntiMicroServer : public QObject
{
    Q_OBJECT

  public:
    explicit LocalAntiMicroServer(QObject *parent = nullptr);

    QLocalServer *getLocalServer() const;

  signals:
    void clientdisconnect();
    void showHiddenWindow();

  public slots:
    void startLocalServer();
    void handleOutsideConnection();
    void handleSocketDisconnect();
    void close();

  private:
    void checkForMessages(QLocalSocket *socket);

    QLocalServer *localServer;
};

#endif // LOCALANTIMICROSERVER_H
