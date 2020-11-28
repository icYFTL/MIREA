import Vue from 'vue'
import App from './App.vue'
import {BootstrapVue} from 'bootstrap-vue'
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'
import Vuex from 'vuex'
import Axios from 'axios'
import router from "./router";
import Router from "vue-router";
import store from "./store"
import Toast from "vue-toastification";
import "vue-toastification/dist/index.css";

Vue.use(Vuex)
Vue.use(Axios)
Vue.use(BootstrapVue)
//Vue.use(IconsPlugin)
Vue.use(Toast)
Vue.use(Router)


Vue.config.productionTip = false
Vue.prototype.$http = Axios;
const token = localStorage.getItem('token') // Still unused actions

if (token)
    Vue.prototype.$http.defaults.headers.common['Authorization'] = token // Still unused actions

new Vue({
    render: h => h(App),
    router,
    store
}).$mount('#app')
