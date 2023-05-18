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
        path: '/sample/employees',
        component: () => import('@/views/sample/employee/EmployeeDemo.vue')
      }
    ]
  }
]

export default routes
