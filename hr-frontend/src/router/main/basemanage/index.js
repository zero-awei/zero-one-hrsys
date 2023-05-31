const routes = [
  {
    path: '/pimportalview',
    name: '门户首页',
    component: () => import('@/views/baseManage/Portal.vue')
  },
  {
    path:'/archivesinfo',
    name:'档案信息',
    component:()=>import('@/views/baseMange/archivesManage/ArchivesInfo.vue')
  },
  {
    path:'/onfilereminder',
    name:'非员工在档提醒',
    component:()=>import('@/views/baseMange/archivesManage/OnFileReminder.vue')
  },
  {
    path:'/outfilereminder',
    name:'员工不在档提醒',
    component:()=>import('@/views/baseMange/archivesManage/OutFileReminder.vue')
  },
  {
    path:'/filetransferrecord',
    name:'档案转出记录',
    component:()=>import('@/views/baseMange/archivesManage/FileTransferRecord.vue')
  },
]

export default routes
