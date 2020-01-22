from manimlib.imports import *

# python -m manim Science3Mins.py S1 -pl
# python -m manim Science3Mins.py HelloWorld -al

class S1(Scene):
    def construct(self):
        grid = NumberPlane()

        self.add(grid)  # Make sure title is on top of grid
        self.play(
            ShowCreation(grid, run_time=3, lag_ratio=0.1),
        )

        ## S1.1-S1.2
        Gear_Han_image = ImageMobject(
            "E:\GitHub\-\Science3Min\Resources\Gear_Han.png"
        ).scale(4)

        self.play(FadeInFromDown(Gear_Han_image))
        self.play(ApplyMethod(Gear_Han_image.scale,0.75))
        self.play(ApplyMethod(Gear_Han_image.shift,LEFT*3))

        Gear_Han_text = TextMobject(
            "\\kaishu 汉铁齿轮"
        ).shift(RIGHT*2.5+UP*1.5).scale(2.25)

        Gear_Han_line = Line(
            np.array([0,2,0]),
            np.array([0,0,0])
        ).shift(RIGHT*0.25)

        Zhengzhou_text = TextMobject(
            "郑州博物馆"
        ).scale(0.75).next_to(Gear_Han_text.get_corner(DL),RIGHT,0).shift(DOWN*0.5)

        Gear_Han_name_group = VGroup(
            Gear_Han_text,
            Zhengzhou_text
        ).next_to(Gear_Han_line).shift(RIGHT*0.25)

        Gear_Han_Detail_text = VGroup(
            TextMobject("汉代时期的机械，推断这些仪器均采用有齿轮。"),
            TextMobject("这件铁齿轮的出土，对于研究我国古代机械工程"),
            TextMobject("的发展，提供了重要的实物资料。")
        ).arrange_submobjects(DOWN,aligned_edge=LEFT,buff=MED_SMALL_BUFF).scale(0.5)
        Gear_Han_Detail_text.next_to(Gear_Han_line.get_corner(DL),RIGHT,0).shift(DOWN*1)

        Gear_Han_group = VGroup(
            Gear_Han_line,Gear_Han_name_group,Gear_Han_Detail_text
        ).shift(DOWN*0.25)

        self.play(
            Write(Gear_Han_line),
            FadeInFrom(Gear_Han_text,LEFT),
            FadeInFrom(Zhengzhou_text,LEFT)
        )
        self.play(Write(Gear_Han_Detail_text))
        self.wait()

        ## S1.3

        ## Cycloidal Gear
        CycloidalGear_image = ImageMobject(
            "E:\GitHub\-\Science3Min\Resources\CycloidalGear.png"
        ).scale(3).shift(LEFT * 3)

        CycloidalGear_text = TextMobject(
            "\\kaishu 摆线齿轮"
        ).shift(RIGHT * 2.5 + UP * 1.5).scale(2.25)

        CycloidalGear_line = Line(
            np.array([0, 2, 0]),
            np.array([0, 0, 0])
        ).shift(RIGHT * 0.25)

        CycloidalGear_time_text = TextMobject(
            "1674"
        ).scale(0.75).next_to(CycloidalGear_text.get_corner(DL), RIGHT, 0).shift(DOWN * 0.5)

        CycloidalGear_name_group = VGroup(
            CycloidalGear_text,
            CycloidalGear_time_text
        ).next_to(CycloidalGear_line).shift(RIGHT * 0.25)

        CycloidalGear_Detail_text = VGroup(
            TextMobject("1674年丹麦天文学家罗默(Ole Rømer)提出用外"),
            TextMobject("摆线齿形能使齿轮等速运动。")
        ).arrange_submobjects(DOWN, aligned_edge=LEFT, buff=MED_SMALL_BUFF).scale(0.5)
        CycloidalGear_Detail_text.next_to(CycloidalGear_line.get_corner(DL), RIGHT, 0).shift(DOWN * 1)

        CycloidalGear_group = VGroup(
            CycloidalGear_line,
            CycloidalGear_name_group,
            CycloidalGear_Detail_text
        ).shift(DOWN * 0.25)

        self.play(
            FadeOutAndShift(Gear_Han_image,LEFT),
            FadeOutAndShift(Gear_Han_group,LEFT)
        )
        self.play(
            FadeInFrom(CycloidalGear_image, RIGHT),
            FadeInFrom(CycloidalGear_group, RIGHT)
        )
        self.wait()

        ## Involute Gear
        Involute_Gear_image = ImageMobject(
            "E:\GitHub\-\Science3Min\Resources\Involute_Gear.png"
        ).scale(3).shift(LEFT * 3)

        Involute_Gear_text = TextMobject(
            "\\kaishu 渐开线齿轮"
        ).shift(RIGHT * 2.5 + UP * 1.5).scale(2.25)

        Involute_Gear_line = Line(
            np.array([0, 2, 0]),
            np.array([0, 0, 0])
        ).shift(RIGHT * 0.25)

        Involute_Gear_time_text = TextMobject(
            "1765"
        ).scale(0.75).next_to(Involute_Gear_text.get_corner(DL), RIGHT, 0).shift(DOWN * 0.5)

        Involute_Gear_name_group = VGroup(
            Involute_Gear_text,
            Involute_Gear_time_text
        ).next_to(Involute_Gear_line).shift(RIGHT * 0.25)

        Involute_Gear_Detail_text = VGroup(
            TextMobject("1765年，欧拉(Euler)提出渐开线齿形解析研究"),
            TextMobject("的数学基础。")
        ).arrange_submobjects(DOWN, aligned_edge=LEFT, buff=MED_SMALL_BUFF).scale(0.5)
        Involute_Gear_Detail_text.next_to(Involute_Gear_line.get_corner(DL), RIGHT, 0).shift(DOWN * 1)

        Involute_Gear_group = VGroup(
            Involute_Gear_line,
            Involute_Gear_name_group,
            Involute_Gear_Detail_text
        ).shift(DOWN * 0.25)

        self.play(
            FadeOutAndShift(CycloidalGear_image, LEFT),
            FadeOutAndShift(CycloidalGear_group, LEFT)
        )
        self.play(
            FadeInFrom(Involute_Gear_image, RIGHT),
            FadeInFrom(Involute_Gear_group, RIGHT)
        )
        self.wait()
        self.play(FadeOut(Involute_Gear_group),buff = 0.5)
        self.play(
            ApplyMethod(Involute_Gear_image.shift,np.array([3,0,0]))
        )

class S3_P1(Scene):
    def construct(self):
        grid = NumberPlane()
        self.add(grid)

        ## S3_12
        self.S3_12()
        self.S3_13()

        ## S3_13 Part1
    def S3_13(self):
        gear1 = ImageMobject("E:\GitHub\-\Science3Min\Resources\Gear_30.png").scale(5)
        d_chinese_text = TextMobject("分度圆").scale(1.75)
        d_english_text = TextMobject("reference circle").next_to(d_chinese_text,DOWN)
        d_text_group = VGroup(
            d_chinese_text,d_english_text
        ).move_to(np.array([0,0,0]))
        self.play(
            FadeInFrom(gear1, DOWN),
            FadeIn(d_text_group)
        )
        reference_circle_circle = Circle(color=WHITE).scale(3.09)
        self.play(
            ShowCreation(reference_circle_circle)
        )
        self.wait()


    def S3_12(self):
        d_chinese_text = TextMobject("分度圆").scale(1.75)
        d_english_text = TextMobject("reference circle").next_to(d_chinese_text,DOWN)
        d_text_group = VGroup(
            d_chinese_text,d_english_text
        ).next_to(np.array([0,0,0]),LEFT,buff = 1)

        m_chinese_text = TextMobject("模数").scale(1.75)
        m_english_text = TextMobject("module").next_to(m_chinese_text, DOWN)
        m_text_group = VGroup(
            m_chinese_text, m_english_text
        ).next_to(np.array([0, 0, 0]), RIGHT,buff = 1.5)

        self.play(FadeInFrom(d_text_group,DOWN))
        self.play(FadeInFrom(m_text_group,DOWN))
        self.play(
            FadeOutAndShift(m_text_group,RIGHT),
            ApplyMethod(d_text_group.move_to,np.array([0,0,0]))
        )

class S3_P2(Scene):
    def construct(self):
        grid = NumberPlane()
        self.add(grid)

        ## S3_13 Part2
        gear1_img = ImageMobject("E:\GitHub\-\Science3Min\Resources\Gear_30.png").scale(5)
        d_chinese_text = TextMobject("分度圆").scale(1.75)
        d_english_text = TextMobject("reference circle").next_to(d_chinese_text, DOWN)
        d_text_group = VGroup(
            d_chinese_text, d_english_text
        ).move_to(np.array([0, 0, 0]))
        gear1_reference_circle_circle = Circle(color = WHITE).scale(3)
        gear1_group = Group(
            gear1_img,
            gear1_reference_circle_circle
        )
        self.add(gear1_group)
        self.play(FadeOut(d_text_group))

        #S3_14
        gear12_img = ImageMobject("E:\GitHub\-\Science3Min\Resources\Gear_30.png").scale(5).shift(LEFT*2).rotate(PI)
        gear2_img = ImageMobject("E:\GitHub\-\Science3Min\Resources\Gear_20.png").scale(3.95)
        gear2_reference_circle_circle = Circle(color = WHITE).scale(2)
        gear2_group = Group(
            gear2_img,gear2_reference_circle_circle
        ).shift((RIGHT*3))
        self.play(
            ApplyMethod(gear1_group.shift,LEFT*2),
            FadeInFrom(gear2_group,RIGHT)
        )

        o1_point = Point(np.array([-2,0,0]))
        o2_point = Point(np.array([3,0,0]))
        o1_text = TexMobject("O_1",color = YELLOW).next_to(o1_point,LEFT)
        o2_text = TexMobject("O_2",color = YELLOW).next_to(o2_point)
        o1o2_line = Line(np.array([-2,0,0]),np.array([3,0,0]),color = YELLOW)
        self.play(
            Rotate(gear1_group,PI,np.array([0,0,1]),run_time=4),
            Rotate(gear2_group,PI/2*3,np.array([0,0,-1]),run_time=4),
            ShowCreation(o1_text),
            ShowCreation(o2_text),
            ShowCreation(o1o2_line)
        )

        ## S3 15
        self.play(
            FadeIn(gear12_img),
            FadeOut(gear1_reference_circle_circle),
            FadeOut(o1_text),
            FadeOut(o2_text),
            FadeOut(o1o2_line),
            ApplyMethod(gear2_img.set_opacity,0.15),
            ApplyMethod(gear2_reference_circle_circle.fade,0.85)
        )

        tooth_thickless_arc = Arc(2*PI/120*11,2*PI/60,color = RED,radius = 3).shift(LEFT*2)
        tooth_thickless_text1 = TextMobject("齿厚(tooth thickness)",color = RED).next_to(tooth_thickless_arc)
        tooth_thickless_text2 = TextMobject("齿厚(tooth thickness)",color = RED).next_to(tooth_thickless_arc)

        spacewidth_arc = Arc(2*PI/120*1,2*PI/60,color = YELLOW,radius = 3).shift(LEFT*2)
        spacewidth_text1 = TextMobject("齿槽宽(spacewidth)",color = YELLOW).next_to(spacewidth_arc)
        spacewidth_text2 = TextMobject("齿槽宽(spacewidth)",color = YELLOW).next_to(spacewidth_arc)

        pitch_arc = Arc(2 * PI / 120 * 111, 2 * PI / 60*2, color=GREEN, radius=3).shift(LEFT * 2)
        pitch_text1 = TextMobject("齿距","(pitch)", color=GREEN).next_to(pitch_arc)
        pitch_text2 = TextMobject("齿距(pitch)", color=GREEN).next_to(pitch_arc)

        self.play(
            ShowCreation(tooth_thickless_text1),ShowCreation(tooth_thickless_text2),
            ShowCreation(spacewidth_text1), ShowCreation(spacewidth_text2),
            ShowCreation(pitch_text1), ShowCreation(pitch_text2)
        )
        self.play(Transform(tooth_thickless_text1,tooth_thickless_arc))
        self.play(Transform(spacewidth_text1, spacewidth_arc))
        self.wait()
        self.play(Transform(pitch_text1, pitch_arc))

        module_formular = TexMobject("{\\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\over\\pi}=")\
            .next_to(pitch_text2,DOWN).shift(np.array([0.3,0.1,0]))
        module_text = TextMobject("模数").next_to(module_formular).shift(UP*0.25)
        self.play(ShowCreation(module_formular))
        self.play(ShowCreation(module_text))

class S3_P3(Scene):
    def construct(self):
        grid = NumberPlane()
        self.add(grid)

        GBT_1_img = ImageMobject("E:\GitHub\-\Science3Min\Resources\GBT_1357_2008_1.png").scale(5).shift(LEFT*3+DOWN*2)
        GBT_4_img = ImageMobject("E:\GitHub\-\Science3Min\Resources\GBT_1357_2008_4.png").scale(5)\
            .move_to(GBT_1_img).shift(np.array([-0.2,0.2,0]))

        GBT_name_text_group = VGroup(
            TextMobject("\\kaishu 通用机械和重型机械用"),
            TextMobject("\\kaishu 圆柱齿轮\\ 模数")
        ).arrange_submobjects(DOWN, aligned_edge=LEFT, buff=MED_SMALL_BUFF).shift(RIGHT * 2.5 + UP * 1.5)

        GBT_line = Line(
            np.array([0, 3, 0]),
            np.array([0, 1, 0])
        ).shift(RIGHT)

        GBT_lable_text = TextMobject(
            "GB/T 1357-2008 "
        ).scale(0.65).next_to(GBT_name_text_group.get_corner(DL), RIGHT, 0).shift(DOWN * 0.5)

        GBT_name_group = VGroup(
            GBT_name_text_group,
            GBT_lable_text
        ).next_to(GBT_line).shift(RIGHT * 0.25)

        self.play(
            GrowFromEdge(GBT_4_img, DOWN),
            GrowFromEdge(GBT_1_img,DOWN)
        )
        self.play(
            Write(GBT_line),
            FadeInFrom(GBT_name_group, LEFT)
        )
        self.play(
            FadeOutAndShift(GBT_1_img,RIGHT),
            FadeOutAndShift(GBT_name_group,RIGHT),
            FadeOutAndShift(GBT_line,RIGHT),
            ApplyMethod(GBT_4_img.shift,4)
        )
        self.play(
            ApplyMethod(GBT_4_img.scale,1.75,run_time = 0.5)
        )

        rect = Rectangle(color = BLUE,height = 5.5).shift(np.array([-1.5,-1,0]))
        self.play(ShowCreation(rect))