<template>
  <el-aside>
    <div class="menu-wrap">
      <el-scrollbar max-height="95vh" :always="true">
        <el-menu
          default-active="0"
          active-text-color="#409EFF"
          text-color="#606266"
          background-color="#fff"
          unique-opened
          router
        >
          <template v-for="(menu, index) in menus" :key="index">
            <!-- 有二级目录的层级 -->
            <el-sub-menu v-if="menu.children" :index="menu.id + ''">
              <template #title>
                <el-icon>
                  <component :is="menu.icon"></component>
                  <span>{{ menu.text }}</span>
                </el-icon>
              </template>
              <!-- 二级目录 -->
              <el-menu-item-group>
                <el-menu-item
                  v-for="(child, idx) in menu.children"
                  :key="idx"
                  :index="child.href"
                >
                  <el-icon>
                    <component :is="child.icon"></component>
                  </el-icon>
                  <span>{{ child.text }}</span>
                </el-menu-item>
              </el-menu-item-group>
            </el-sub-menu>
            <!-- 没有二级目录的层级 -->
            <el-menu-item v-else :index="menu.href">
              <el-icon>
                <component :is="menu.icon"></component>
              </el-icon>
              <span>{{ menu.text }}</span>
            </el-menu-item>
          </template>
        </el-menu>
      </el-scrollbar>
    </div>
  </el-aside>
</template>

<script setup>
import { Menu as IconMenu, Location, User } from '@element-plus/icons-vue'
import { reactive, ref } from 'vue'
const prop = defineProps({
  menus: {
    type: Array,
    default: () => []
  }
})
</script>

<style lang="scss" scoped>
.el-aside {
  background-color: #fff;
  height: 100%;
  width: 241px;
  border-right: 1px solid #ccc;
  .menu-wrap {
    width: 240px;
  }
}
.el-menu {
  border: 0;
}
.el-menu-item {
  cursor: pointer;
  font-size: 18px;
  &:hover {
    background-color: #ecf1f7;
  }
  :deep(.el-sub-menu__title) {
    :deep(.el-icon) {
      margin-left: 20px !important;
      font-style: normal !important;
    }
  }
}

.el-sub-menu__title > .el-icon,
.el-sub-menu > .el-icon {
  width: 100%;
  svg {
    margin-right: 10px;
  }
  span {
    display: block;
    width: 100%;
    text-align: left;
  }
}
</style>
