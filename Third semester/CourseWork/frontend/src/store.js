import Vue from 'vue'
import Vuex from 'vuex'
import axios from 'axios'
import Home from "./components/modules/Profile";
//import menu from "./configs/menu.json"

Vue.use(Vuex)
export default new Vuex.Store({
    state: {
        status: '',
        token: localStorage.getItem('token') || '',
        user: {},
        current_module: Home,
        is_menu_opened: false,
        menu_content: null
    },
    mutations: {
        change_module(state, new_module) {
            state.current_module = new_module;
        },
        change_active_module(state, module_name){
            state.menu_content.forEach(function (item, i, arr) {
                arr[i].is_active = item.title === module_name;
            })
        },
        toggle_menu(state){
            state.is_menu_opened = !state.is_menu_opened;
        },
        set_menu_items(state, items){
          state.menu_content = items;
        },
        auth_request(state) {
            state.status = 'loading'
        },
        auth_success(state, token, user) {
            state.status = 'success'
            state.token = token
            state.user = user
        },
        auth_error(state) {
            state.status = 'error'
        },
        logout(state) {
            state.status = ''
            state.token = ''
        }
    },
    getters: {
        isLoggedIn: state => state.token, //!!state.token, /// Temporary
        authStatus: state => state.status,
    },
    actions: {
        login({commit}, user) {
            return new Promise((resolve) => {
                commit('auth_request')
                axios({url: 'http://localhost:3000/login', data: user, method: 'POST'})
                    .then(resp => {
                        const token = resp.data.token
                        const user = resp.data.user
                        localStorage.setItem('token', token)
                        axios.defaults.headers['Authorization'] = token
                        commit('auth_success', token, user)
                        resolve(resp)
                    })
                    .catch(() => {
                        commit('auth_error')
                        localStorage.removeItem('token')
                        //reject(err)
                        resolve(); // Because I don't have backend yet
                    })
            })
        },
        logout({commit}) {
            return new Promise((resolve) => {
                commit('logout')
                localStorage.removeItem('token')
                delete axios.defaults.headers['Authorization']
                resolve()
            })
        }
    }
})