import Request from '@/apis/request'

const baseUrl = import.meta.env.VITE_HR_J1_3 + '/sys-user'

export const addUser = (data, success, fail) => {
  Request.requestForm(Request.POST, baseUrl + '/add', data)
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

export const deleteUser = (data, success, fail) => {
  Request.requestForm(Request.DELETE, baseUrl + '/delete', data)
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
