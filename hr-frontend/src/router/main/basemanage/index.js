const routes = [
  {
    path: '/syqyggridview',
    name: '试用员工',
    component: () => import('@/views/baseManage/Syqyg.vue')
  },
  {
    path: '/ltxyggridview',
    name: '离退休员工',
    component: () => import('@/views/baseManage/Ltxyg.vue')
  },
  {
    path: '/pimportalview',
    name: '�Ż���ҳ',
    component: () => import('@/views/baseManage/Portal.vue')
  },
  {
    path: '/blacklist',
    name: 'BlackList',
    component: () => import('@/views/baseMange/information/BlackList.vue')
  },
  {
    path: '/review',
    name: 'InformationReview',
    component: () =>
      import('@/views/baseMange/information/InformationReview.vue')
  },
  {
    path: '/employee',
    name: 'EmployInformation',
    component: () =>
      import('@/views/baseMange/information/EmployeeInformation.vue')
  },
  {
    path: '/roster',
    name: 'StaffRoster',
    component: () => import('@/views/baseMange/roster/roster.vue')
  },
  {
    path: '/trainee',
    name: 'TraineeEmployee',
    component: () => import('@/views/baseMange/roster/trainee.vue')
  },
  {
    path: '/lzyghmcgridview',
    name: '离职员工',
    component: () => import('@/views/baseManage/Lzyg.vue')
  },
  {
    path: '/jdryhmcgridview',
    name: '借调员工',
    component: () => import('@/views/baseManage/Jdyg.vue')
  },
  {
    path: '/gzryhmcgridview',
    name: '挂职员工',
    component: () => import('@/views/baseManage/Gzyg.vue')
  }
]

export default routes
