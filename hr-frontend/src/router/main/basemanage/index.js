const routes = [
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
    path: '/retiree',
    name: 'Rettiree',
    component: () => import('@/views/baseManage/retirement/retiree.vue')
  },
  {
    path: '/expense',
    name: 'ExpenseLedger',
    component: () => import('@/views/baseManage/retirement/expense.vue')
  },
  {
    path: '/contractCatrgory',
    name: 'contractCatrgory',
    component: () =>
      import('@/views/baseManage/datesetting/ContractCategory.vue')
  },
  {
    path: '/contractType',
    name: 'contractType',
    component: () => import('@/views/baseManage/datesetting/ContractType.vue')
  },
  {
    path: '/practiceCertificate',
    name: 'practiceCertificate',
    component: () =>
      import('@/views/baseManage/datesetting/PracticeCertificate.vue')
  },
  {
    path: '/pimportalview',
    name: 'pimportalview',
    component: () => import('@/views/baseManage/Portal.vue')
  },
  {
    path: '/postcertificateview',
    name: 'postcertificateview',
    component: () =>
      import('@/views/baseManage/standardSetting/PostCertificate.vue')
  },
  {
    path: '/jobtitlecatalog',
    name: 'jobtitlecatalog',
    component: () =>
      import('@/views/baseManage/standardSetting/JobTitleCataloge.vue')
  },
  {
    path: '/archives',
    name: 'archives',
    component: () => import('@/views/baseManage/standardSetting/Archives.vue')
  },
  {
    path: '/syqyggridview',
    name: 'syqyggridview',
    component: () => import('@/views/baseManage/roster/Syqyg.vue')
  },
  {
    path: '/ltxyggridview',
    name: 'ltxyggridview',
    component: () => import('@/views/baseManage/roster/Ltxyg.vue')
  },
  {
    path: '/pimportalview',
    name: 'pimportalview',
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
    name: 'lzyghmcgridview',
    component: () => import('@/views/baseManage/roster/Lzyg.vue')
  },
  {
    path: '/jdryhmcgridview',
    name: 'jdryhmcgridview',
    component: () => import('@/views/baseManage/roster/Jdyg.vue')
  },
  {
    path: '/gzryhmcgridview',
    name: 'gzryhmcgridview',
    component: () => import('@/views/baseManage/roster/Gzyg.vue')
  },
  {
    path: '/dispatch',
    name: '劳务派遣公司',
    component: () => import('@/views/baseManage/contractManage/Dispatch.vue')
  },
  {
    path: '/contract',
    name: '合同信息',
    component: () => import('@/views/baseManage/contractManage/Contract.vue')
  },
  {
    path: '/initsigning',
    name: '初签(续签)提醒',
    component: () => import('@/views/baseManage/contractManage/InitSigning.vue')
  },
  {
    path: '/termination',
    name: '终止提醒',
    component: () => import('@/views/baseManage/contractManage/Termination.vue')
  }
]

export default routes
