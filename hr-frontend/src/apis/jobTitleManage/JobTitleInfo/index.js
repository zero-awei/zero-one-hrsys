import Request from '@/apis/request'

const baseUrl = import.meta.env.VITE_HR_C6_1 + '/job-title-management'

export const addJobTitleInfo = (data,success, fail) => {
    Request.requestJson(Request.POST, baseUrl + '/add-jobtitle', data)
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

export const deleteJobTitleInfo = (data,success, fail) => {
    Request.requestJson(Request.DELETE, baseUrl + '/remove-jobtitle', data)
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