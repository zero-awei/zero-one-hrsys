const routes = [
  {
    path: '/home',
    name: 'Home',
    redirect: { name: 'pimportalview' },
    component: () => import('@/views/HomeView.vue'),
    children: [
      {
        path: '/dashboard',
        name: 'Dashboard',
        component: () => import('@/views/dashboard/Dashboard.vue')
      }
    ]
  }
]

// 读取子目录下面菜单设置为二级路由
const secondRouter = import.meta.glob('./**/index.js', { eager: true })
for (const path in secondRouter) {
  routes[0].children.push(...secondRouter[path].default)
}
export default routes
