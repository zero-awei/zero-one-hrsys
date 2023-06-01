//分页查询数据列表
const currBaseUrl = '/workhistory/'
export const select= (data, success, fail) => {
    const $store = userStore()
    Request.requestJson(Request.GET, currBaseUrl + 'select', data)
        .then((data) => {
            // 记录Token到本地
            if (data.data) {
                $store.setToken(data.data)
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
            // 记录Token到本地
            if (data.data) {
                $store.setToken(data.data)
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

//调入档案
// export const workhistory = (data, success, fail) => {
//     const $store = userStore()
//     Request.requestJson(Request.GET, currBaseUrl + 'export', data)
//         .then((data) => {
//             // 记录Token到本地
//             if (data.data) {
//                 $store.setToken(data.data)
//                 // 执行成功回调
//                 success()
//                 return
//             }
//             // 执行失败回调
//             fail()
//         })
//         .catch((err) => {
//             // 打印错误信息
//             console.warn(err)
//             // 执行失败回调
//             fail()
//         })
// }

// 1.分页查询数据列表
// {
//     "code": 10000,
//     "message": "success",
//     "data": {
//       "pageIndex": 1,
//       "pageSize": 5,
//       "total": 0,
//       "pages": 0,
//       "rows": []
//     }
//   }
// 2.导出数据（导出本页在前端完成）
// {
//     "code": 10000,
//     "message": "success",
//     "data": "string"
//   }
// 3.调入档案