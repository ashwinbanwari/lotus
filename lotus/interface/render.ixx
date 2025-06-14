export module lotus:render;

import std;

class Shader;
class State;

export class Drawer {
  public:
    Drawer(const Drawer &) = delete;
    Drawer &operator=(const Drawer &) = delete;
    Drawer(Drawer &&) noexcept = default;
    Drawer &operator=(Drawer &&) noexcept = default;

    virtual ~Drawer() = default;

    virtual void draw(State *state) = 0;

  protected:
    Drawer();
};

export class BasicTriangleDrawer final : public Drawer {
  public:
    BasicTriangleDrawer();
    ~BasicTriangleDrawer() = default;

    void draw(State *state) override;

  private:
    unsigned int m_shaderProgram1 = 0;
    unsigned int m_shaderProgram2 = 0;
    unsigned int m_VAO = 0;
};

export class BasicTextureDrawer final : public Drawer {
  public:
    BasicTextureDrawer();
    ~BasicTextureDrawer() = default;

    void draw(State *state) override;

  private:
    std::shared_ptr<Shader> m_shader;
    unsigned int m_VAO;
    unsigned int m_texture;
    int width, height;
};
