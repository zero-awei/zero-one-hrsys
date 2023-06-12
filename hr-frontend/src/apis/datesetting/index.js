// 执业资格证书

import Request from '@/apis/request'

const baseUrl = import.meta.env.VITE_HR_C6_1 + '/contract-management'
// 合同类别
export const contractType = (data, success, fail) => {
  Request.requestJson(Request.GET, baseUrl + '/query-contract', data)
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
// 合同类型
