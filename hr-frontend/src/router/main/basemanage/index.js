const routes = [
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
  }
]

export default routes
