import Router from 'vue-router'
import store from './store.js'
import Login from './components/Login'
import WorkSpace from "./components/WorkSpace";



let router = new Router({
    mode: 'history',
    routes: [
        {
            path: '/',
            name: 'app',
            component: WorkSpace,
            meta: {
                requiresAuth: true,
                title: "PX | Workspace"
            }
        },
        {
            path: '/login',
            name: 'login',
            component: Login,
            meta: {
                title: "PX | Authentication"
            }
        }
    ]
})

router.beforeEach((to, from, next) => {
    document.title = to.meta.title
    if (to.matched.some(record => record.meta.requiresAuth))
        if(store.getters.isLoggedIn)
            next()
        else
            next('/login')
    else
        next()

})

export default router