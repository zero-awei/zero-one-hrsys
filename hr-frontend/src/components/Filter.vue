<template>
  <el-button @click="IsshowFilter = !IsshowFilter">过滤</el-button>

  <div class="filter-bar" v-show="IsshowFilter">
    <div class="filter-left">
      <el-form inline="true" label-position="right">
        <form-item
          v-for="(item, index) in info.itemArr"
          :key="index"
          class="filter-items"
        >
          <el-form-item
            :label="item.name"
            v-show="typeof item.val === 'string'"
          >
            <el-input placeholder="" v-model="form.itemArr[index].val" />
          </el-form-item>

          <el-form-item
            :label="item.name"
            v-show="typeof item.val === 'object'"
          >
            <el-select
              placeholder="请选择..."
              v-model="form.itemArr[index].val"
              clearable
            >
              <el-option
                v-for="context in item.val"
                :label="context"
                :value="context"
                :key="context"
              />
            </el-select>
          </el-form-item>
        </form-item>
      </el-form>
    </div>
    <div class="filter-right">
      <el-button @click="resetFilter">重置</el-button>
      <el-button type="primary" @click="submitFilter">搜索</el-button>
    </div>
  </div>
  <!-- table数据模拟 -->
  <el-table :data="filteredTableData">
    <el-table-column prop="zuzhi" label="组织" width="180" />
    <el-table-column prop="xinming" label="姓名" width="180" />
    <el-table-column prop="zhengjianhao" label="证件号" />
  </el-table>
</template>

<script>
export default {
  name:"Filter",
  data() {
    return {
      IsshowFilter: false,
      tableData: [
        { zuzhi: "成都分公司", xinming: "sayori", zhengjianhao: 123 },
        { zuzhi: "蓝海", xinming: "sayoriqwq", zhengjianhao: 12 },
        { zuzhi: "成都蓝海", xinming: "saqwq", zhengjianhao: 12344 },
      ],

      info: {
        itemArr: [
          {
            name: "组织",
            val: ["成都分公司", "蓝海"],
          },
          {
            name: "姓名",
            val: "",
          },
          {
            name: "证件号码",
            val: "",
          },
        ],
      },

      form: {
        itemArr: [
          {
            name: "组织",
            val: "",
          },
          {
            name: "姓名",
            val: "",
          },
          {
            name: "证件号码",
            val: "",
          },
        ],
      },
    };
  },
  mounted() {
    sessionStorage.setItem("formData", JSON.stringify(this.form));
  },
  computed: {
    filteredTableData() {
      return this.tableData.filter((item) => {
        const Match1 = item.xinming.includes(this.form.itemArr[1].val);
        const Match2 = item.zuzhi.includes(this.form.itemArr[0].val);
        const Match3 = item.zhengjianhao
          .toString()
          .includes(this.form.itemArr[2].val);

        return Match1 && Match2 && Match3;
      });
    },
  },
  methods: {
    async submitFilter() {
      console.log("带着筛选过的内容发请求", this.form);
    },
    resetFilter() {
      this.form = JSON.parse(sessionStorage.getItem("formData"));
    },
  },
};
</script>

<style scoped>
.filter-bar {
  display: flex;
}
</style>
