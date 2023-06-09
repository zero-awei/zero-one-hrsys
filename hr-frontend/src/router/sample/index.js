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
        component: () => import('@/views/sample/sass/SassSample.vue')
      },
      {
        path: '/sample/communication',
        component: () => import('@/views/sample/communication/Index.vue')
      },
      {
        path: '/sample/tablehead',
        component: () => import('@/views/sample/tableHead/TableHead.vue')
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
      },
      {
        path: '/sample/edit',
        component: () => import('@/views/sample/edit/Edit.vue')
      },
      {
        path: '/sample/qualification',
        component: () =>
          import('@/views/sample/qualification/Qualification.vue')
      },
      {
        path: '/sample/search',
        component: () => import('@/views/sample/search/Search.vue')
      },

      {
        path: '/sample/feedback',
        component: () => import('@/views/sample/feedbackTest/Feedback.vue')
      },
      {
        path: '/sample/employees',
        component: () => import('@/views/sample/employee/EmployeeDemo.vue')
      },
      {
        path: '/sample/filter',
        component: () => import('@/views/sample/filter/FilterDemo.vue')
      },
      {
        path: '/sample/selection',
        component: () => import('@/views/sample/selection/orgSelection.vue')
      }
    ]
  }
]

export default routes
