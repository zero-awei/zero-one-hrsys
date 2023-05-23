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
        component: () => import('@/views/sample/sassTest/SassSample.vue')
      },
      {
        path: '/sample/communication',
        component: () => import('@/views/sample/communication/Index.vue')
      },
      {
        path: '/sample/Aside',
        component: () => import('@/views/sample/aside/Aside.vue')
      },
      {
        path: '/sample/echarts',
        component: () => import('@/views/sample/echarts_test/Echart.vue')
      },
      {
        path: '/sample/pagination',
        component: () => import('@/views/sample/pagination/PaginationDemo.vue')
      },
      {
        path: '/sample/maintable',
        component: () => import('@/views/sample/maintable/Maintable.vue')
      },
      {
        path: '/sample/process',
        component: () => import('@/views/sample/process/ProcessDemo.vue')
      }
    ]
  }
]

export default routes
