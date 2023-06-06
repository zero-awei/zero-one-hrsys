//分页查询数据列表
const currBaseUrl = '/workhistory/'
export const select= (data, success, fail) => {
    const $store = userStore()
    Request.requestJson(Request.GET, currBaseUrl + 'select', data)
        .then((data) => {
            // 获取非员工在档提醒数据
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

//导出数据（导出本页在前端完成）
export const workhistory = (data, success, fail) => {
    const $store = userStore()
    Request.requestJson(Request.GET, currBaseUrl + 'export', data)
        .then((data) => {
            // 导出数据
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

// 分页查询数据列表  ✓
// 导出数据（导出本页在前端完成）  ✓
// 调入档案