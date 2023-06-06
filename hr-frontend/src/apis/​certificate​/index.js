import Request from '../request'
import { usePostCertificateStore } from '@/stores/postCertificate'

const currBaseUrl = '/certificate/'

export const addPostCertificate = (data,success, fail) => {
    const $store = usePostCertificateStore()
    Request.requestForm(Request.POST, currBaseUrl + 'query-certificate', data)
      .then((data) => {
        if (data.data) {
          $store.tableData = data.data
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