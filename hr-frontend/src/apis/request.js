import http from 'axios'

/**
 * 封装一个Http请求工具类
 */
export default class Request {
  static get GET() {
    return 1
  }
  static get POST() {
    return 2
  }
  static get PUT() {
    return 3
  }
  static get DELETE() {
    return 4
  }

  /**
   * 发送请求
   * @param method 请求方式，如Request.GET
   * @param url 请求地址
   * @param data 上传数据
   * @param upType 上传数据方式，如http.upType.form
   * @param options [可选]其他配置选项
   * @returns {Promise} 请求发送后的Promise对象
   */
  static request(method, url, data, upType, options = null) {
    // 组装参数
    const config = {
      url: url,
      upType: upType,
      ...options
    }
    switch (method) {
      case Request.GET:
        config.method = 'get'
        config.params = data
        break
      case Request.POST:
        config.method = 'post'
        config.data = data
        break
      case Request.PUT:
        config.method = 'put'
        config.data = data
        break
      case Request.DELETE:
        config.method = 'delete'
        config.data = data
        break
    }
    return http.request(config)
  }

  /**
   * 发送表单请求
   * @param method 请求方式，如Request.GET
   * @param url 请求地址
   * @param data 上传数据
   * @param options [可选]其他配置选项
   * @returns {Promise} 请求发送后的Promise对象
   */
  static requestForm(method, url, data, options = null) {
    return Request.request(method, url, data, http.upType.form, options)
  }

  /**
   * 发送JSON请求
   * @param method 请求方式，如Request.GET
   * @param url 请求地址
   * @param data 上传数据
   * @param options [可选]其他配置选项
   * @returns {Promise} 请求发送后的Promise对象
   */
  static requestJson(method, url, data, options = null) {
    return Request.request(method, url, data, http.upType.json, options)
  }

  /**
   * 发送带文件上传的请求，该方法会完成js数据对象转换成FormData对象操作
   * 请求方式以post方式发送
   * @param url 请求地址
   * @param data 包括file数据的js数据对象
   * @param options [可选]其他配置选项
   * @returns {Promise} 请求发送后的Promise对象
   */
  static postFile(url, data, options = null) {
    //将data转换成FormData对象
    const formData = new FormData()
    for (let key in data) {
      formData.append(key, data[key])
    }
    //发送请求
    return Request.request(
      Request.POST,
      url,
      formData,
      http.upType.file,
      options
    )
  }
}
