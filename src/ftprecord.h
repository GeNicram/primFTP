#ifndef FTPRECORD_H
#define FTPRECORD_H

#include <QObject>

/*! This file define structure for stored ftp server settings. Files are loaded
 * from JSON file if following construction:
 * {
 *   "storedFtp": [
 *     {
 *       id: 1,
 *       name: "x",
 *       address: "xxx.com",
 *       path: "/a/b/c",
 *       user: "z",
 *       password: "xxx"
 *     }
 *   ]
 * }
 */

struct FtpRecord
{
public:
    FtpRecord();
    int id;
    QString name;
    QString address;
    QString path;
    QString user;
    QString password;
};

#endif // FTPRECORD_H
