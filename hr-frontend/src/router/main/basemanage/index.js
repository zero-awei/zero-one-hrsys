const routes = [
  {
    path: '/pimportalview',
    name: '门户首页',
    component: () => import('@/views/baseManage/Portal.vue')
  },
  {
    path: '/postcertificateview',
    name: '岗位证书',
    component: () => import('@/views/baseManage/standardSetting/PostCertificate.vue')   
  },
  {
    path: '/jobtitlecatalog',
    name: '职称目录',
    component: () => import('@/views/baseManage/standardSetting/JobTitleCataloge.vue')   
  },
  {
    path: '/archives',
    name: '档案室',
    component: () => import('@/views/baseManage/standardSetting/Archives.vue')   
  },
]

export default routes
