const routes = [
  {
    path: '/rightsmanage',
    name: '权限管理',
    component: () => import('@/views/sysManage/RightsManage.vue')
  },
  {
    path: '/menumanage',
    name: '菜单管理',
    component: () => import('@/views/sysManage/MenuManage.vue')
  },
  {
    path: '/rolesmanage',
    name: '角色管理',
    component: () => import('@/views/sysManage/RolesManage.vue')
  },
  {
    path: '/usersmanage',
    name: '用户管理',
    component: () => import('@/views/sysManage/UsersManage.vue')
  }
]

export default routes
