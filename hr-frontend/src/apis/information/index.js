import Request from '@/apis/request'

const baseUrl = import.meta.env.VITE_HR_C3_1 + '/employee-information'

export const addInfomation = (data,success, fail) => {
    Request.requestJson(Request.POST, baseUrl + '/add-new-info', data)
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

