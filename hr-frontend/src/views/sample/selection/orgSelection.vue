<template>
  <el-card>
    <el-button text @click="openDialog">点击搜索</el-button>
    <Selection ref="selectDialog" :tableData="tableData" :xmlData="xmlData" />
  </el-card>
</template>

<script setup>
import Selection from '@/components/orgSelection/Selection.vue'
const selectDialog = ref(null)
const openDialog = () => {
  selectDialog.value.toggleState()
}
// 定义表单数据
const xmlData = [
  { id: 0, name: '排序' },
  { id: 1, name: '组织名称', prop: 'orgName' },
  { id: 2, name: '员工简称', prop: 'orgAbbrName' },
  { id: 3, name: '组织编号', prop: 'orgId' },
  { id: 4, name: '上级组织', prop: 'supOrgName' },
  { id: 5, name: '所属区域', prop: 'owningRegion' },
  { id: 6, name: '补贴标准', prop: 'subsidy' },
  { id: 7, name: '组织启用时间', prop: 'enabledTime' },
  { id: 8, name: '启停标识', prop: 'outageMark' }
]
const tableData = [
  {
    orgId: '0001',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0002',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0003',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0004',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0005',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  },
  {
    orgId: '0006',
    orgName: '蓝海集团',
    orgAbbrName: '蓝海',
    supOrgName: '零一星球',
    owningRegion: '四川',
    subsidy: '',
    enabledTime: '',
    outageMark: '停用'
  }
]
</script>

<style lang="scss" scoped></style>

