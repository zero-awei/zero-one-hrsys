import Request from '../../request'

const currBaseUrl = '/certificate/'

export const addPostCertificate = (data,success, fail) => {
    Request.requestForm(Request.POST, currBaseUrl + 'add-certificate', data)
      .then((data) => {
        if (data.data===0) {
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

export const deletePostCertificate = (data,success, fail) => {
  Request.requestForm(Request.DELETE, currBaseUrl + 'remove-certificate', data)
    .then((data) => {
      if (data.data===0) {
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