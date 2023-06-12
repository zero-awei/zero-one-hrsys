import Request from '@/apis/request'

const baseUrl = import.meta.env.VITE_HR_C2_2

export const addCertificateInfo = (data,success, fail) => {
    Request.requestJson(Request.POST, baseUrl + '/add-CreateNewCer', data)
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

export const deleteCertificateInfo = (data,success, fail) => {
    Request.requestJson(Request.DELETE, baseUrl + '/remove-certif', data)
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