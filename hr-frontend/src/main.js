import { createApp } from 'vue'
import { createPinia } from 'pinia'
import * as echarts from 'echarts'

import App from './App.vue'
import router from './router'
import 'element-plus/dist/index.css'
import 'element-plus/theme-chalk/src/message.scss'
import * as ElementPlusIconsVue from '@element-plus/icons-vue'
import './assets/main.css'
import ECharts from './components/echarts/ECharts.vue'

import zhCn from 'element-plus/dist/locale/zh-cn.mjs'
import ElementPlus from 'element-plus'

// import ECharts from './components/echarts/echart-with-color.vue'

import 'nprogress/nprogress.css'

const app = createApp(App)
app.use(createPinia())
app.use(router)
app.use(ElementPlus, {
  locale: zhCn
})
app.config.globalProperties.$echarts = echarts
app.component('echarts', ECharts) //注册 ECharts 组件

app.mount('#app')
// 安装HTTP中间件
import installHttp from './plugins/http'
installHttp(router)

// 安装ElIcon
import installElIcon from './plugins/el-icon'
installElIcon(app)

// 全局事件总线
import mitt from 'mitt'
app.config.globalProperties.$bus = mitt()

for (const [key, component] of Object.entries(ElementPlusIconsVue)) {
  app.component(key, component)
}
