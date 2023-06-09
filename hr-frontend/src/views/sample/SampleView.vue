<template>
  <div>
    <el-header>
      <div class="header-nav">示例效果演示页</div>
    </el-header>
    <el-container>
      <el-aside>
        <div class="menu-wrap">
          <el-scrollbar max-height="95vh">
            <el-menu
              default-active="0"
              active-text-color="#409EFF"
              text-color="#fff"
              background-color="#545c64"
              unique-opened
              router
            >
              <el-menu-item
                v-for="(menu, index) in menus"
                :key="index"
                :index="menu.path"
              >
                <el-icon>
                  <icon-menu />
                </el-icon>
                <span>{{ menu.text }}</span>
              </el-menu-item>
            </el-menu>
          </el-scrollbar>
        </div>
      </el-aside>
      <el-main>
        <router-view />
      </el-main>
    </el-container>
  </div>
</template>

<style lang="scss" scoped>
.el-header {
  background-color: #5d6672;
  height: 5vh;
  display: flex;
  justify-content: space-between;
  padding: 0;
  .header-nav {
    line-height: 5vh;
    width: 100%;
    color: #f8f8f8;
    text-align: center;
  }
}
.el-aside {
  background-color: #545c64;
  height: 95vh;
  width: 221px;
  .menu-wrap {
    width: 220px;
  }
}
.el-menu {
  border: 0;
}
.el-main {
  padding: 0px;
  background-color: #edecec;
  height: 95vh;
}
</style>

<script setup>
import { reactive } from 'vue'
// 演示菜单数据，添加新的演示在这里补充数据即可 path代表路由地址 text代表提示文本
const menus = reactive([
  {
    path: '/sample',
    text: '空白页'
  },
  {
    path: '/sample/excel',
    text: 'Excel演示'
  },
  {
    path: '/sample/print',
    text: '打印演示'
  },
  {
    path: '/sample/edit',
    text: '信息编辑页'
  },
  {
    path: '/sample/sass',
    text: 'sass演示'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信'
  },
  {
    path: '/sample/pagination',
    text: '分页'
  },
  {
    path: '/sample/echarts',
    text: 'Echarts演示'
  },
  {
    path: '/sample/maintable',
    text: '表格主体测试页面'
  },
  {
    path: '/sample/aside',
    text: '侧边栏'
  },
  {
    path: '/sample/process',
    text: '进度条'
  },
  {
    path: '/sample/qualification',
    text: '资格图表数据'
  },
  {
    path: '/sample/search',
    text: '搜索框'
  },
  {
    path: '/sample/tablehead',
    text: '表头演示'
  },

  {
    path: '/sample/feedback',
    text: '消息反馈演示'
  },
  {
    path: '/sample/employees',
    text: '人员信息'
  },
  {
    path: '/sample/filter',
    text: '过滤器'
  },
  {
    path: '/sample/selection',
    text: '上级组织选择示例页面'
  }
])
</script>
