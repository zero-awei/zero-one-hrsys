<template>
    <div>
        <p>{{tableTitle}}</p>
        <ul>
            <li v-if="tableOperations[0].is">
                <AddButton :tableTitle="tableTitle" :addData="addData"/>
            </li>
        </ul>
    </div>
</template>

<script setup>
import AddButton from "./add-button.vue"

defineProps(['tableTitle','tableOperations','addData'])
</script>

<style scoped>
li{
    list-style-type: none;
}
</style>