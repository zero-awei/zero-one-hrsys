import { LeaveStaffStore } from '@/stores/leaveStaff'
import Request from '../request'

const baseUrl = import.meta.env.VITE_HR_C2_2
/**
 * 通用接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

//参数:
/**
 * pageIndex
 * pageSize
 * ---------
 * id_or_name
 */

//分页查询借调员工信息
export const getLzygData = (data, success, fail) => {
  const $store = LeaveStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/query-all-FormerEmployees', data)
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

//导出离职人员
export const exportLzygData = (data, success, fail) => {
  const $store = LeaveStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/query-ExportRetirees', data)
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
