import Request from '@/apis/request'

const baseUrl = (import.meta.env.VITE_HR_J1_3 = '/sys-mange' + '/sys-menu')

export const addMenu = (data, success, fail) => {
  Request.requestForm(Request.POST, baseUrl + '/add-menu', data)
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

export const deleteMenus = (data, success, fail) => {
  Request.requestForm(Request.DELETE, baseUrl + '/remove-menu', data)
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调1
      fail()
    })
}
