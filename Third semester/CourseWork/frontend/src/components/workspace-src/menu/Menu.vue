<!-- TODO: Recreate menu. -->
<template>
    <div class="content">
        <div class="nav__bar">
            <a href="#" class="nav__trigger" v-on:click="trigger_click">
                <div class="bars"></div>
            </a>
        </div>
        <transition name="slide-fade">
            <template v-if="this.$store.state.is_menu_opened">
                <MenuContent :items=construct_menu()></MenuContent>
            </template>
        </transition>
    </div>
</template>

<script>
    import MenuContent from "./MenuContent";

    import Profile from "../../modules/Profile";
    import Tasks from "../../modules/Tasks";
    import Settings from "../../modules/Settings";
    import Rating from "../../modules/Rating";

    export default {
        name: "Menu",
        components: {MenuContent},
        methods: {
            trigger_click: function () {
                this.$store.commit('toggle_menu')
            },

            construct_menu: function () {
                console.warn(this.$store.state.menu_content)
                if (this.$store.state.menu_content === null)
                    this.$store.state.menu_content = [
                        {
                            "title": "Me",
                            "module": Profile,
                            "is_active": true
                        },
                        {
                            "title": "Tasks",
                            "module": Tasks,
                            "is_active": false
                        },
                        {
                            "title": "Rating",
                            "module": Rating,
                            "is_active": false
                        },
                        {
                            "title": "Settings",
                            "module": Settings,
                            "is_active": false
                        }
                    ];

                return this.$store.state.menu_content;
                // this.menu_items_content.forEach(function (item, i, arr) {
                //     try {
                //         import("../../modules/" + item.title).then(result => {
                //             arr[i].module = Vue.component(item.title,result);
                //             console.warn(result)
                //         });
                //         console.log("imported " + item.title);
                //     } catch (e) {
                //         console.error(e);
                //         arr[i].module = null;
                //     }
                // });
                // return this.menu_items_content;
                // TODO: Refactoring & Optimization
            }
        },


    }
</script>

<style lang="scss" scoped>
    // Colors
    $primary: #7d87a8;
    $primary-ultralight: mix(white, $primary, 65%);
    $primary-light: mix(white, $primary, 40%);
    $primary-dark: mix(black, $primary, 40%);
    $primary-ultradark: mix(black, $primary, 80%);
    $black: #333333;
    $white: #eeeeee;

    .slide-fade-enter-active {
        transition: all .3s ease;
    }

    .slide-fade-leave-active {
        transition: all .8s cubic-bezier(1.0, 0.5, 0.8, 1.0);
    }

    .slide-fade-enter, .slide-fade-leave-to {
        transform: translateX(-10px);
        opacity: 0;
    }

    // Fonts
    @import url(https://fonts.googleapis.com/css?family=Open+Sans:400|Raleway:300,700);
    $open-sans: 'Open Sans', Helvetica, arial, sans-serif;
    $raleway: 'Raleway', 'Open Sans', sans-serif;

    // Misc
    $nav-bar-width: 60px;
    $bar-length: 28px;
    $bar-thickness: 4px;


    // --------------------------------------
    // Navigation
    // --------------------------------------
    .nav__bar {
        position: fixed;
        top: 0;
        bottom: 0;
        left: 0;
        width: $nav-bar-width;
        height: 100vh;
        border-right: 1px solid rgba($primary, 0.25);
        background-color: $primary-ultradark;
        z-index: 99;
    }

    .nav__trigger {
        display: block;
        position: absolute;
        top: 50%;
        left: ($nav-bar-width/2) - ($bar-length/2);
        padding: ($bar-thickness*2) 0;
        margin-top: -(($bar-thickness*5) / 2);
        transition: 0.2s ease-in-out;
        z-index: 99;

        .bars {
            position: relative;

            &,
            &:before,
            &:after {
                width: $bar-length;
                height: $bar-thickness;
                background-color: $primary;
                transition: 0.2s ease-in-out;
                border-radius: $bar-thickness;
            }

            &:before,
            &:after {
                content: '';
                display: block;
                position: absolute;
                top: 0;
                left: 0;
                will-change: transform;
            }

            &:before {
                transform: translateY(-($bar-thickness*2));
            }

            &:after {
                transform: translateY(($bar-thickness*2));
            }
        }

        &.is-active {
            transform: rotate(-45deg);

            .bars {
                &:before,
                &:after {
                    transform: translateX(0) rotate(-90deg);
                }
            }
        }
    }


</style>