#include "auth_plugin.h"
#include <ctkPluginContext.h>

AuthPlugin::AuthPlugin(ctkPluginContext* context)
{
    context->registerService<AuthPluginService>(this);
}

bool AuthPlugin::login(const QString& username, const QString& password)
{
    if (QString::compare(username, "root") == 0
            && QString::compare(password, "123456") == 0) {
        return true;
    } else {
        return false;
    }
}
