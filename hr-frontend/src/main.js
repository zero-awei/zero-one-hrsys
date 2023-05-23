import { createApp } from 'vue'
import { createPinia } from 'pinia'

import * as echarts from 'echarts'

import App from './App.vue'
import router from './router'
import 'element-plus/theme-chalk/src/message.scss'
import './assets/main.css'
import ECharts from './components/echarts/ECharts.vue'
// import ECharts from './components/echarts/echart-with-color.vue'

const app = createApp(App)
app.use(createPinia())
app.use(router)

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
