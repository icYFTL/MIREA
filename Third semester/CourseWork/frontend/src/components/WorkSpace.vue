<template>
    <div class="workspace">
        <div class="content">
            <Menu ref="menu"></Menu>
            <ModuleView class="module-view" :module=current_module></ModuleView>
        </div>
    </div>
</template>

<script>
    import Menu from "./workspace-src/menu/Menu";
    import ModuleView from "./workspace-src/ModuleView";
    import Home from "./modules/Profile";

    export default {
        name: "WorkSpace",
        components: {ModuleView, Menu},
        computed: {
            current_module: function () {
                return this.$store.state.current_module || Home;
            },
        }
    }
</script>

<style lang="scss" scoped>
    $nav-bar-width: 60px;
    $module-view-width: 100vw;
    $module-view-height: 100vh;

    .content {
        display: inline;
    }

    .module-view {
        width: calc(100% - #{$nav-bar-width});
        height: $module-view-height;
        margin-left: $nav-bar-width;
    }

</style>