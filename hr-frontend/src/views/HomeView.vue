<template>
  <div class="layout-container">
    <el-container class="sec-container">
      <Aside :menus="menus" style="height: 100vh"></Aside>
      <el-container>
        <!-- 导航栏 -->
        <el-header>
          <div class="header-nav">{{ userInfo }}</div>
        </el-header>
        <el-main>
          <!-- 布局路由 -->
          <router-view />
        </el-main>
      </el-container>
    </el-container>
  </div>
</template>

<style lang="scss" scoped>
.sec-container {
  height: 100vh;
}
.el-menu-item-group .el-menu-item {
  text-indent: 1.5em;
}
.el-main {
  padding: 20px;
}
.el-header {
  background-color: #fff;
  display: flex;
  justify-content: space-between;
  padding: 0;
  .header-nav {
    padding: 20px;
    background-color: #6c777f;
    width: 100%;
    color: #f8f8f8;
    text-align: right;
  }
}

.el-aside {
  background-color: #f7fafc !important;
}
</style>

<script setup>
import { ref } from 'vue'
import { userStore } from '../stores/user'
import Aside from '@/components/aside/Aside.vue'
const store = userStore()

// 用户信息提示
const userInfo = ref(
  '欢迎用户：' + (store.getUser === null ? '游客' : store.getUser.username)
)

// 菜单数据
const menus = store.getMenus
</script>
