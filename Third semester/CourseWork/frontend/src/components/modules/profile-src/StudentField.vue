<template>
    <div class="s-field">
        <img src="../../../assets/empty_avatar.png"> <!-- PREVIEW -->
        <a>Semen<br>Belov</a> <!-- PREVIEW -->
    </div>
</template>

<script>
    export default {
        name: "StudentField"
    }
</script>

<style scoped>
    .s-field{
        display: flex;
        flex-flow: column nowrap;
        align-items: center;
    }
    .s-field img{
        width: 100px;
        height: 100px;
    }

    .s-field a {
        margin-top: 0.5em;
    }
</style>