#ifndef AUTH_PLUGIN_SERVICE_H
#define AUTH_PLUGIN_SERVICE_H

#include <QtPlugin>
#include <QString>

class AuthPluginService
{
public:
    virtual ~AuthPluginService() {}
    virtual bool login(const QString& username, const QString& password) = 0;
};

#define AuthService_iid "org.commontk.service.AuthService"

Q_DECLARE_INTERFACE(AuthPluginService, AuthService_iid)

#endif // AUTH_PLUGIN_SERVICE_H
