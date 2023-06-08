import Request from '../request'
// 接口的前缀都在env环境变量里，配置全局变量的目的：
// 后续服务器可能无法转发，需要更改前缀，为避免大量的更改，统一配置前缀，可以简化该过程
// 获取某个接口的前缀
// VITE的环境变量，需要以VITE为前缀
const baseUrl = import.meta.env.VITE_HR_C1_1 // /pull-list

export const getPrefix = async (data, success, fail) => {
  // 获得前缀之后，将其拼接到接口中就行了
  // 该接口仅供环境变量演示示例，请求路径可能有误
  const { datas } = await Request.requestForm(
    Request.POST,
    baseUrl + 'auth-login',
    data
  )
}
