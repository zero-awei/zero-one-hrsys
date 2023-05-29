const routes = [
  {
    path: '/pimportalview',
    name: '门户首页',
    component: () => import('@/views/baseManage/Portal.vue')
  },
  {
    path: '/userInfo',
    name: '员工信息',
    component: () => import('@/views/baseManage/userInfo/index.vue')
  }
]

export default routes
