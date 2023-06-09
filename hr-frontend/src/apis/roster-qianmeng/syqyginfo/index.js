import { ProbationaryStaffStore } from '@/stores/syqyg'
import Request from '../request'

const baseUrl = import.meta.env.VITE_HR_C2_2
/**
 * 通用接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

//试用员工:
/**
 * 参数:
 * pageIndex
 * pageSize
 * -----------
 * id_or_name
 * id
 * name
 * zjhm
 * organization
 * bm
 * ygzt
 * zgzt
 */

/* 响应:
{
  "code": 10000,
  "message": "success",
  "data": {
    "pageIndex": 1,
    "pageSize": 5,
    "total": 0,
    "pages": 0,
    "rows": []
  }
}
 */

//分页查询试用员工信息
export const getSyygData = (data, success, fail) => {
  const $store = ProbationaryStaffStore()
  Request.requestJson(
    Request.GET,
    baseUrl + '/query-all-ProbationaryEmployee',
    data
  )
    .then((data) => {
      if (data.data) {
        //存token
        $store.setToken(data.data)
        success()
        {
          return
        }
      }
      fail()
    })
    .catch((err) => {
      console.warn(err)
      fail()
    })
}

//导出离退休人员
export const exportSyygData = (data, success, fail) => {
  const $store = ProbationaryStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/get-ProbationaryEmployee', data)
    .then((data) => {
      if (data.data) {
        //存token
        $store.setToken(data.data)
        success()
        {
          return
        }
      }
      fail()
    })
    .catch((err) => {
      console.warn(err)
      fail()
    })
}
