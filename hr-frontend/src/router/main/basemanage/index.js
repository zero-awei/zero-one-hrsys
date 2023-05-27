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
  }
]

export default routes
