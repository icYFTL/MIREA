<template>
    <nav class="nav" ref="nav">
        <ul class="nav__list" ref="nav_list">
            <li class="nav__item" v-for="(item, idx) in items" :key="idx"><a v-on:click="menu_click(item)"
                                                                             v-bind:class="item.is_active ? 'is-active' : ''">{{item.title}}</a>
            </li>
        </ul>
    </nav>
</template>

<script>
    export default {
        name: "MenuContent",
        props: {
            items: Array
        },
        methods: {
            menu_click: function (item) {
                this.$store.commit('change_module', item.module)
                this.$store.commit('toggle_menu')
                this.$store.commit('change_active_module', item.title)
            }
        }

    }
</script>

<style lang="scss" scoped>
    $primary: #7d87a8;
    $primary-ultralight: mix(white, $primary, 65%);
    $primary-ultradark: mix(black, $primary, 80%);
    $primary-light: mix(white, $primary, 40%);
    $mobile-width: 600px;
    $nav-bar-width: 60px;

    @import url(https://fonts.googleapis.com/css?family=Open+Sans:400|Raleway:300,700);
    $raleway: 'Raleway', 'Open Sans', sans-serif;

    .nav {
        position: fixed;
        top: 0;
        right: 0;
        bottom: 0;
        left: 0;
        background-color: $primary-ultradark;
        z-index: 0;
    }

    .nav__list {
        overflow: hidden;
        position: absolute;
        top: 50%;
        left: 0;
        width: 100%;
        margin: 0;
        padding-left: $nav-bar-width;
        list-style: none;
        font-family: $raleway;
        transform: translateY(-50%);

        .nav__item {
            padding: 0.5rem 1rem;

            @media (min-width: $mobile-width) {
                width: percentage(1/3);
                padding: 0.5rem 1rem;
            }
        }

        a {
            display: inline-block;
            color: $primary;
            font-size: 1rem;
            line-height: 1.5;
            cursor: pointer;

            &:hover {
                color: $primary-light;
            }

            &.is-active {
                color: $primary-ultralight;
            }

            @media (min-width: $mobile-width) {
                font-size: 1.5rem;
            }
        }
    }
</style>