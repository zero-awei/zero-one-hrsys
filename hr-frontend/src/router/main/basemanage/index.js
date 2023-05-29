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
  {
    path: '/syqyggridview',
    name: '试用员工',
    component: () => import('@/views/baseManage/roster/Syqyg.vue')
  },
  {
    path: '/ltxyggridview',
    name: '离退休员工',
    component: () => import('@/views/baseManage/roster/Ltxyg.vue')
  },
  {
    path: '/pimportalview',
    name: '�Ż���ҳ',
    component: () => import('@/views/baseManage/roster/Portal.vue')
  },
  {
    path: '/blacklist',
    name: 'BlackList',
    component: () => import('@/views/baseManage/information/BlackList.vue')
  },
  {
    path: '/review',
    name: 'InformationReview',
    component: () =>
      import('@/views/baseManage/information/InformationReview.vue')
  },
  {
    path: '/employee',
    name: 'EmployInformation',
    component: () =>
      import('@/views/baseManage/information/EmployeeInformation.vue')
  },
  {
    path: '/roster',
    name: 'StaffRoster',
    component: () => import('@/views/baseManage/roster/roster.vue')
  },
  {
    path: '/trainee',
    name: 'TraineeEmployee',
    component: () => import('@/views/baseManage/roster/trainee.vue')
  },
  {
    path: '/lzyghmcgridview',
    name: '离职员工',
    component: () => import('@/views/baseManage/roster/Lzyg.vue')
  },
  {
    path: '/jdryhmcgridview',
    name: '借调员工',
    component: () => import('@/views/baseManage/roster/Jdyg.vue')
  },
  {
    path: '/gzryhmcgridview',
    name: '挂职员工',
    component: () => import('@/views/baseManage/roster/Gzyg.vue')
  }
]

export default routes
