<template>
  <!-- 使用侧边栏需要传递数据，同时要给侧边栏设置高度，用vh单位 -->
  <Aside :menus="menus" style="height: 95vh"></Aside>
</template>

<script setup>
import Aside from '@/components/aside/Aside.vue'

const menus = reactive([
  {
    path: '/sample',
    text: '空白页',
    icon: 'user'
  },
  {
    path: '/sample/excel',
    text: 'Excel演示',
    icon: 'user'
  },
  {
    path: '/sample/print',
    text: '打印演示',
    icon: 'user'
  },
  {
    path: '/sample/edit',
    text: '信息编辑页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  }
])
</script>

<style></style>
