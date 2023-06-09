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
    path: '/retireStaff',
    name: 'retireStaff',
    component: () => import('@/views/baseManage/roster/RetireStaff.vue')
  },
  {
    path: '/Leavestaff',
    name: 'leaveStaff',
    component: () => import('@/views/baseManage/roster/LeaveStaff.vue')
  },
  {
    path: '/jdryhmcgridview',
    name: 'jdryhmcgridview',
    component: () => import('@/views/baseManage/roster/Jdyg.vue')
  },
  {
    path: '/temporyStaff',
    name: 'temporyStaff',
    component: () => import('@/views/baseManage/roster/TemporyStaff.vue')
  },
  {
    path: '/dispatch',
    name: 'Dispatch',
    component: () => import('@/views/baseManage/contractManage/Dispatch.vue')
  },
  {
    path: '/contract',
    name: 'Contract',
    component: () => import('@/views/baseManage/contractManage/Contract.vue')
  },
  {
    path: '/initsigning',
    name: 'InitSigning',
    component: () => import('@/views/baseManage/contractManage/InitSigning.vue')
  },
  {
    path: '/termination',
    name: 'Termination',
    component: () => import('@/views/baseManage/contractManage/Termination.vue')
  },
  {
    path: '/certificateinfo',
    name: 'CertificateInfo',
    component: () =>
      import('@/views/baseManage/certificateManage/CertificateInfo.vue')
  },
  {
    path: '/jobtitleinfo',
    name: 'JobTitleInfo',
    component: () =>
      import('@/views/baseManage/jobTitleManage/JobTitleInfo.vue')
  },
  {
    path: '/businessabroad',
    name: 'BusinessAbroad',
    component: () => import('@/views/baseManage/goAbroad/BusinessAbroad.vue')
  },
  {
    path: '/privateabroad',
    name: 'PrivateAbroad',
    component: () => import('@/views/baseManage/goAbroad/PrivateAbroad.vue')
  },
  {
    path: '/orginfo',
    name: 'OrgInfo',
    component: () => import('@/views/baseManage/orginfo/OrgInfo.vue')
  },
  {
    path: '/archivesinfo',
    name: 'ArchivesInfo',
    component: () =>
      import('@/views/baseManage/archivesManage/ArchivesInfo.vue')
  },
  {
    path: '/onfilereminder',
    name: 'OnFileReminder',
    component: () =>
      import('@/views/baseManage/archivesManage/OnFileReminder.vue')
  },
  {
    path: '/outfilereminder',
    name: 'OutFileReminder',
    component: () =>
      import('@/views/baseManage/archivesManage/OutFileReminder.vue')
  },
  {
    path: '/filetransferrecord',
    name: 'FileTransferRecord',
    component: () =>
      import('@/views/baseManage/archivesManage/FileTransferRecord.vue')
  },
  {
    path: '/orginfo',
    name: 'OrgInfo',
    component: () => import('@/views/baseManage/orginfo/OrgInfo.vue')
  }
]

export default routes
