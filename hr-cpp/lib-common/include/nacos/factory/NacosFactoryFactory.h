#ifndef NACOS_FACTORY_FACTORY_H
#define NACOS_FACTORY_FACTORY_H
#include "INacosServiceFactory.h"
#include "../NacosString.h"
namespace nacos {
class NacosFactoryFactory {
public:
    static INacosServiceFactory *getNacosFactory(const NacosString &_configFile);
    static INacosServiceFactory *getNacosFactory(Properties &_props);
};
}
#endif