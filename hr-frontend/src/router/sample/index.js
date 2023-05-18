const routes = [
  {
    path: '/sample',
    name: 'Sample',
    component: () => import('@/views/sample/SampleView.vue'),
    children: [
      {
        path: '/sample/excel',
        component: () => import('@/views/sample/excel/Excel.vue')
      },
      {
        path: '/sample/print',
        component: () => import('@/views/sample/print/Print.vue')
      },
      {
        path: '/sample/sass',
        component: () => import('@/views/sample/SassTest/SassSample.vue')
      },
      {
        path: '/sample/communication',
        component: () => import('@/views/sample/Communication/index.vue')
      },
      {
        path: '/sample/maintable',
        component: () => import('@/views/sample/maintable/maintable.vue')
      }
    ]
  }
]

export default routes